//Cracked by Roath
// stone.c
// Jay 7/4/96

#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

string* names = ({
	"����ʯ","ʯ��","��ʯͷ",
});

string* longs = ({
	"����һ�鲻̫��Ķ���ʯ��\n",
	"����һ��������ǵ�ʯ�顣\n",
	"����һ������Ĵ�ʯͷ��\n",
});

void create()
{
    int i = random(sizeof(longs));

    set_name(names[i], ({"shikuai", "shi", "stone"}));
    set_weight(i*500 + 300); 
    if( clonep() )
       set_default_object(__FILE__);
    else {
       set("long", longs[i]);
	set("unit","��");
	set("wield_msg","$N����һ��ʯͷ׼��ս����\n");
	set("material", "stone");
    }
    init_hammer(i+1);
    setup();
}
