//OBJ:/d/lingshedao/obj/tlblade.c
#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
        set_name(HIC"������"NOR, ({ "tulong dao", "dao" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("treasure",1);
                set("unit", "��");
                set("long", "����Ǻų����������������,��������޹�,
�ഫ�ǹ������ط�����,�����������������������.\n");
        set("value", 100000);
                set("material", "steel");
                set("no_get",1);
                set("no_put",1);
                set("no_drop","���²�֪�ж�����������ѱ���,�����ܰ�������?\n");
                set("no_give","���û?��ô�õı�����������?\n");
                set("wield_msg", HIC"������������Ϣ�ĵ���$N����,����
��ʱ��������,��Ȼ����һ��ɱ��.\n" NOR);
                set("unwield_msg",HIC"$N��������,���Ϸ����ǽ��ľ��
����֮��,ɱ��Ҳ����������ȥ.\n"NOR);
             }
                init_blade(600); 
                setup();
}


void owner_is_killed()
{
       destruct(this_object());
}

int query_autoload()
{
       return 1;
}
