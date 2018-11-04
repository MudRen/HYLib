// rope.c

#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name( "皮鞭", ({ "whip" ,"pi bian","bian" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 1200);
                set("material", "skin");
        }
        init_whip(1);

        set("wield_msg", "$N从腰间抽出一条$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n束在腰间。\n");

        setup();
}

