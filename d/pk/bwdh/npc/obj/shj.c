//shanyu-jin ɺ����
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("ɺ����", ({ "shanhu jin", "shanhu","jin" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ɺ�����ɵĹ��ȣ������ߵ��Ժ��׵��ز��������ֽ���\n"
"��ͣ��ں�������ǧ�������ɺ�����������ж�������ʯ������\n"
"�������۶���������У���֮���ۡ�\n"
);
                set("value", 1000000);
                set("treasure", 1);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_staff(100);
        setup();
}
