// ����֮��
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"����֮��"NOR, ({"light sword", "light sword"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY"����һ������֮��,�������侫�¡������й���������!\n"NOR);
                set("unique", 1);
                set("value", 50000);
                set("treasure",1);       
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("armor_prop/armor", 60);
                set("armor_prop/karay",10);
                                set("no_give",1);
                set("no_get",1);
                set("no_put",1);

                set("armor_prop/percao",10);
                set("wield_str", 30);        
                set("treasure",1);       
                set("wield_msg",HIY"һ��ҫ�۵Ĺ�â���� ��$N�����϶����һ������֮����\n"NOR);
                set("unwield_msg",HIY"$N�������е�����֮����ҫ�۵Ĺ�âҲ������ʧ�ˡ�\n"NOR);
        }
     init_sword(800);
        setup();
}       

mixed hit_ob(object me, object victim, int damage_bonus)
{
int a;
 if (random(6)==0)
{
a = (int)me->query_skill("magic-light", 1);
a=520+a*2;
if (victim->query("qi") > a)
                victim->receive_damage("qi", a);
a=420+a;
if (victim->query("eff_qi") > a)
                victim->receive_wound("qi", a);
message_vision(HIY"$n������֮��������֮��ɨ����!!\n"NOR, me,victim);
}
 if (victim->query("magicgift")==5
 && random(3)==0)
{
a = (int)me->query_skill("magic-light", 1);
a=520+a*2;
if (victim->query("qi") > a)
                victim->receive_damage("qi", a);
a=420+a;
if (victim->query("eff_qi") > a)
                victim->receive_wound("qi", a);
message_vision(HIY"$n������֮��������֮��ɨ����!!\n"NOR, me,victim);
}
}