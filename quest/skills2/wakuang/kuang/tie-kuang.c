// tie-kuang.c 铁矿石  
// 星星lywin 2000/8/27

#include <ansi.h>
inherit ITEM;  
void create() 
{
        set_name(CYN"铁矿石"NOR,({"tie kuang", "kuang"}));
        set_weight(50000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
		set("no_drop","不要乱丢，这东西打到人痛！\n");
		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);

		set("no_put",1);
                set("long", "这是一块沉重的铁矿石。\n");
             }
        setup();
}
