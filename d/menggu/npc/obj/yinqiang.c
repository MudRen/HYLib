// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// yinqiang.c
// updated 5-30-97, pickle

#include <ansi.h>
#include <weapon.h>

inherit CLUB;

void create()
{
        set_name(HIW "����ǹ" NOR, ({"silver spear", "qiang", "spear"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","���ǰѳ��صĳ�ǹ��ǹ���Ǵ������ƣ������ޱȣ�\n");
                set("value", 18000);
                set("wield_msg","$N�ó�һ��$n�������У���ǰ����һ�����⣮\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_club(70);
        setup();
}

