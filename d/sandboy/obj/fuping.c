#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"��Ƽ"NOR, ({ "fuping","ping" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ƭ");
                set("material", "wood");
                set("long","һ�������ڳ����е�"+HIG+"��ɫ"+NOR+"ˮ��.\n");
        }
        setup();
}

