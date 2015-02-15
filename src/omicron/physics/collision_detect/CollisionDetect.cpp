#include "CollisionDetect.hpp"

namespace omi {

//------------------------------------------------------------------------------
//                                   VARIABLES
//------------------------------------------------------------------------------

std::vector<CollisionDetector*> CollisionDetect::m_detectors;
std::map<std::string, std::vector<CollisionDetector*>>
        CollisionDetect::m_groups;
std::vector<CheckPair> CollisionDetect::m_check;

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void CollisionDetect::checkGroup(const std::string& a, const std::string& b) {

    // TODO: check pair doesn't already exists
    CheckPair pair;
    pair.a = a;
    pair.b = b;
    m_check.push_back(pair);
}

void CollisionDetect::update() {
    
    m_groups.clear();

    // clear collision data on all detector
    for (std::vector<CollisionDetector*>::iterator detector =
         m_detectors.begin(); detector != m_detectors.end(); ++detector) {

        (*detector)->clearData();
        // sort into a map
        std::string group = (*detector)->getGroup();
        // if the group doesn't already exist create it
        if (m_groups.find(group) == m_groups.end()) {

            m_groups.insert(
                std::make_pair(group, std::vector<CollisionDetector*>()));
        }
        m_groups[group].push_back(*detector);
    }

    // go over each check pair
    for (std::vector<CheckPair>::iterator it = m_check.begin();
         it != m_check.end(); ++it) {

        // go over each item in the first group
        for (std::vector<CollisionDetector*>::iterator first = 
            m_groups[it->a].begin();
            first != m_groups[it->a].end(); ++first) {

            // go over each item in the second groups
            for (std::vector<CollisionDetector*>::iterator second = 
                m_groups[it->b].begin();
                second != m_groups[it->b].end(); ++second) {

                // perform collision detection
                if (first != second) {

                    processDetectors(*first, *second);
                }
            }
        } 
    }
}

void CollisionDetect::addDetector(CollisionDetector* detector) {

    m_detectors.push_back(detector);

    // std::string group = detector->getGroup();

    // // if the group doesn't already exist create it
    // if (m_groups.find(group) == m_groups.end()) {

    //     m_groups.insert(
    //         std::make_pair(group, std::vector<CollisionDetector*>()));
    // }

    // m_groups[group].push_back(detector);
}

void CollisionDetect::removeDetector(CollisionDetector* detector) {

   for (std::vector<CollisionDetector*>::iterator it = m_detectors.begin();
        it != m_detectors.end();) {

       if (*it == detector) {

           it = m_detectors.erase(it);
       }
       else {

           ++it;
       }
   }
}

void CollisionDetect::clear() {

    m_check.clear();
    m_groups.clear();
}

//------------------------------------------------------------------------------
//                            PRIVATE MEMBER FUNCTIOSN
//------------------------------------------------------------------------------

void CollisionDetect::processDetectors(
    CollisionDetector* a, CollisionDetector* b) {

    // iterate over each bounding in the first detector
    for (std::vector<std::unique_ptr<BoundingShape>>::iterator first =
         a->m_boundings.begin(); first != a->m_boundings.end(); ++first) {

        // iterate over each bounding in the second detector
        for (std::vector<std::unique_ptr<BoundingShape>>::iterator second =
            b->m_boundings.begin(); second != b->m_boundings.end(); ++second) {

            // check if the boundings are touching
            if (checkCollision(first->get(), second->get())) {

                // pass data back to the detector
                a->detected(b->getOwner(), b->getGroup());
            }
        }
    }
}

bool CollisionDetect::checkCollision(BoundingShape* a, BoundingShape* b) {

    // TODO: need to do type checks here
    return checkCircleCircle(
        dynamic_cast<BoundingCircle*>(a), dynamic_cast<BoundingCircle*>(b));
}

bool CollisionDetect::checkCircleCircle(BoundingCircle* a, BoundingCircle* b) {

    // check if circles are colliding
    float distance = util::vec::distance(
        a->getTransform()->translation, b->getTransform()->translation);

    return distance <= a->getRadius() + b->getRadius();
}

} // namespace omi