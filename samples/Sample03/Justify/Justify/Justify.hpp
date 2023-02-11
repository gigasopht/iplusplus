// justify.hpp -- Justified type program

enum text_justify
{
    text_left = 0,  // text is left aligned
    text_right = 1,  // text is right aligned
    text_center = 2,  // text is centered
    text_justified = 3   // text is left and right justified
};

void justify(handle Device,
    const character* text,
    const irectangle* bounds,
    unsigned alignment);

void draw_ruler(handle device,
    const irectangle* rectangle);

character text[] =

L"Call me Ishmael. Some years ago -- never mind "
L"how long precisely -- having little or no money "
L"in my purse, and nothing particular to interest "
L"me on shore, I thought I would sail about a "
L"little and see the watery part of the world. It "
L"is a way I have of driving off the spleen, and "
L"regulating the circulation. Whenever I find "
L"myself growing grim about the mouth; whenever "
L"it is a damp, drizzly November in my soul; "
L"whenever I find myself involuntarily pausing "
L"before coffin warehouses, and bringing up the "
L"rear of every funeral I meet; and especially "
L"whenever my hypos get such an upper hand of me, "
L"that it requires a strong moral principle to "
L"prevent me from deliberately stepping into the "
L"street, and methodically knocking people's hats "
L"off -- then, I account it high time to get to sea "
L"as soon as I can. This is my substitute for "
L"pistol and ball. With a philosophical flourish "
L"Cato throws himself upon his sword; I quietly "
L"take to the ship. There is nothing surprising "
L"in this. If they but knew it, almost all men in "
L"their degree, some time or other, cherish very "
L"nearly the same feelings towards the ocean with "
L"me.";


