//
// Created by James Miller on 11/30/2024.
//

#pragma once

namespace MillerGui
{

    class SubWindowInterface
    {
    public:
        virtual ~SubWindowInterface() = default;

        virtual void Open() = 0;

        virtual void Close() = 0;

        virtual void Draw() = 0;
    };

};