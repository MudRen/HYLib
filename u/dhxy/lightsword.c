// ��֮��
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"��֮��"NOR, ({"light jian", "lightsword"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY"����һ�ѹ�֮��,�������侫�¡���������Ų�֮һ!\n"NOR);
                set("unique", 1);
                set("value", 0);
		set("no_put", 1);
		set("no_put", 1);
		set("no_get", 1);
		set("no_drop", 1);
		set("no_pawn", 1);
                set("treasure",1);       
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("skill", ([
                        "name": "magic-light",
                        "exp_required": 20000000,
                        "difficulty": 300,
                        "min_skill":  500,
                             "max_skill": 1000,              
                ]) );
                set("armor_prop/attack", 30);	
       set("armor_prop/armor", 60);
        set("armor_prop/karay",15);
        set("armor_prop/percao",15);
                set("treasure",1);       
                set("wield_msg",HIY"һ��ҫ�۵�ʥ����� ��$N�����϶����һ�ѹ�֮����\n"NOR);
                set("unwield_msg",HIY"$N�����еĹ�֮�����뽣�ʡ�ҫ�۵�ʥ��Ҳ������ʧ�ˡ�\n"NOR);
        }
     init_sword(1777);
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

mixed hit_ob(object me, object victim, int damage_bonus)
{
int a;
if (1)
if (random(4)==0)
{
message_vision(HIY"$N���ϵĹ�֮��ͻȻʥ�����!!һ��ʥ��������$N������!!\n"NOR, me,victim);
message_vision(HIY"�ظ�ʥ��!!  $Nȫ��е��ޱȵ����ʣ���\n"NOR, me,victim); 
	if((int)me->query("qi") < (int)me->query("max_qi")+(int)me->query("max_qi")/3)
        {
        me->add("qi",me->query("eff_qi")/6);
        me->add("eff_qi",me->query("eff_qi")/6);
if (me->query("qi") > me->query("max_qi")+1000)
me->set("qi",me->query("max_qi")+1000);
if (me->query("eff_qi") > me->query("max_qi"))
me->set("eff_qi",me->query("max_qi"));
        }
	if((int)me->query("jing") < (int)me->query("max_jing")+(int)me->query("max_jing")/3)
        {
        me->add("jing",me->query("eff_jing")/6);
        me->add("eff_jing",me->query("eff_jing")/6);
if (me->query("jing") > me->query("max_jing")+1000)
me->set("jing",me->query("max_jing")+1000);
if (me->query("eff_jing") > me->query("max_jing"))
me->set("eff_jing",me->query("max_jing"));

         }
message_vision(HIY"$N���ϵ������˲���!!\n"NOR, me,victim);
}
if (random(4)==1)
{
message_vision(HIY"$N���ϵĹ�֮��ͻȻʥ�����!!$N����������ʥ��!!\n"NOR, me,victim);
message_vision(HIY"��֮����!!  $Nȫ������ҫ�۵Ĺ�â����\n"NOR, me,victim); 
 if ( random(me->query("combat_exp"))>(int)victim->query("combat_exp")/3)
{
if (!victim->is_busy())
victim->start_busy(2);
message_vision(HIY"$n��������������!!\n"NOR, me,victim);
}
else message_vision(HIY"$n����Ծ���ӹ���һ�ѡ�!\n"NOR, me,victim);
}
if (me->is_busy())
{
me->start_busy(1);
message_vision(HIY"$N�ڹ�֮���޵������£��ָ����ж�!!\n"NOR, me,victim);
}
}