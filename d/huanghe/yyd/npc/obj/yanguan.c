// hanyanguan ���̹�

#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("���̹�", ({ "han yanguan", "yanguan" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ֧ͭ�Ƶĺ��̹ܣ����滹ʣ����ĩ����\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", "$N����һ֧���̹ܣ����ϻ𣬵�����ǣ������������\n");
                set("unwield_msg", "$N�Ѻ��̹���Ь�����һྣ�С�ĵطŻػ��\n");
        }
        init_staff(28);
        setup();
}

