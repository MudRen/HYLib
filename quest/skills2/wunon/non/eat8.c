// ë�� /clone/eat/food/mao_sun.c
// by lala, 1997-12-16

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(HIM"����"NOR, ({"tao zi", "taozi","peach"}));
    set_weight(30000);
    set("long", "һ������������Ц�Ĵ�����");
		set("no_drop","��Ҫ�Ҷ����ⶫ������ʹ��\n");
		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);

		set("no_put",1);

    set("unit", "��");
        set( "value", 700 + random( 600 ) );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
}

