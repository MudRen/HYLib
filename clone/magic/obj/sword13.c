// ����֮��
#include <ansi.h>
#include <weapon.h>
inherit AXE;
inherit F_UNIQUE;

void create()
{
        set_name(HIR"��������"NOR, ({"earth meteor", "earth meteor"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY"����һ�Ѱ�������,�������侫�¡������д�ص�����!\n"NOR);
                set("unique", 1);
                set("value", 50000);
                                set("no_give",1);
                set("no_get",1);
                set("no_put",1);

                set("treasure",1);       
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("treasure",1);       
                set("wield_msg",HIY"һ����ɫ�Ĺ�â���� ��$N�����϶����һ��ˮ��ذ�ס�\n"NOR);
                set("unwield_msg",HIY"$N�������е�ˮ��ذ�ס���ɫ�Ĺ�âҲ������ʧ�ˡ�\n"NOR);
        }
     init_axe(800);
        setup();
}       

mixed hit_ob(object me, object victim, int damage_bonus)
{
int a;
 if (victim->query("magicgift")==3
 && random(3)==0)
{
a = (int)me->query_skill("magic-earth", 1);
a=420+a*2;
if (victim->query("qi") > a)
                victim->receive_damage("qi", a);
a=420+a;
if (victim->query("eff_qi") > a)
                victim->receive_wound("qi", a);
message_vision(HIY"$n����������������!!\n"NOR, me,victim);
}
}