#ifndef GAMEPATH_H
#define GAMEPATH_H
#include <string>

namespace StiGame {

enum Paths { AssetRoot, AssetGui, AssetSprite };

/// \class GamePath
/// \brief Static Class to handle File path
class GamePath
{
    public:
        GamePath();
		/// \brief Get the specified path
		/// \param p Path
		/// \return File Path
        static std::string getPath(Paths p);
		/// \brief Combine two path together
		/// \param p1 First Path
		/// \param p2 Second Path
		/// \return Combined Path
        static std::string combine(std::string p1, std::string p2);
		/// \brief Get the specified path
		/// \param p Path
		/// \param p2 Second Path
		/// \return Combined Path
        static std::string getFilepath(Paths p, std::string p2);
        virtual ~GamePath();
    protected:
    private:
		/// \brief Asset Dir Root
        const static std::string assetsDir;
};

}

#endif // GAMEPATH_H
