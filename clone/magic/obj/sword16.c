// ����֮��
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name(HIR"����֮��"NOR, ({"dark blade", "dark blade"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIR"����һ�ѻ���֮��,�������侫�¡������кڰ�������!\n"NOR);
                set("unique", 1);
                set("value", 50000);
                set("treasure",1);       
                set("wield_neili", 2000);
                set("no_give",1);
                set("no_get",1);
                set("no_put",1);
                set("wield_maxneili", 3000);
                set("armor_prop/dexterity",10);
                set("armor_prop/constitution",10);
                set("armor_prop/armor", 30);
                set("wield_str", 30);        
                set("treasure",1);       
                set("wield_msg",HIR"һ��Ѫ��Ĺ�â���� ��$N�����϶����һ�ѻ���֮�С�\n"NOR);
                set("unwield_msg",HIR"$N�������еĻ���֮�С�Ѫ��Ĺ�âҲ������ʧ�ˡ�\n"NOR);
        }
     init_blade(880);
        setup();
}       

mixed hit_ob(object me, object victim, int damage_bonus)
{
int a;
 if (random(6)==0)
{
a = (int)me->query_skill("magic-dark", 1);
a=520+a*2;
if (victim->query("qi") > a)
                victim->receive_damage("qi", a);
a=420+a;
if (victim->query("eff_qi") > a)
                victim->receive_wound("qi", a);
message_vision(HIR"$n������֮�еĻ���֮��ɨ����!!\n"NOR, me,victim);
}
 if (victim->query("magicgift")==6
 && random(3)==0)
{
a = (int)me->query_skill("magic-dark", 1);
a=520+a*2;
if (victim->query("qi") > a)
                victim->receive_damage("qi", a);
a=420+a;
if (victim->query("eff_qi") > a)
                victim->receive_wound("qi", a);
message_vision(HIR"$n������֮�еĻ���֮��ɨ����!!\n"NOR, me,victim);
}
}