// ����������

#include <ansi.h>
inherit ITEM;
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

void create()
{
        set_name(HIW"����������"NOR, ({ "wball axes", "22axes" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ħ���������ʹ��(spell id)�����ħ����\n") ;

                set("unit", "��");
                set("value", 140000);
                set("zhen", 3);
        }
        setup();
}

void init()
{
        add_action("do_shot","spell");
}

int do_shot(string arg)
{
        object me,ob,target;
        int myskill , tgskill;
        int mylev ,damage;
        int damagic;
        string msg;
        object weapon;
        me = this_player();

 	if (!id(arg))
	return notify_fail("���޷�ʹ���������!\n");
        if( !arg ) return notify_fail("�����˭ʹ�ú��������᣿\n");

      if( !target ) target = offensive_target(me);

      if( !target || !target->is_character() || !me->is_fighting(target) )
              return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !target->is_character() || target->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if( me->query("combat_exp")< 500000)
        return notify_fail("��ľ���̫���ò��ˣ�\n");


	if((int)me->query_skill("magic-water",1))
damage = (int)me->query_skill("magic-water", 1);
else damage = 200+random(500);
if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
        if(me->is_busy() )
                return notify_fail("����æ���ġ�\n");

        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIW"\n$N"HIW"�ϵ�ħ������������!  $N"HIW"��ʧ�ˡ�\n"NOR,this_object(),target);
        destruct(this_object());
return 1;
                }

        if( !objectp(ob = present("wball axes", me)) )
                return notify_fail("��û�����ֶ�����\n");

        message_vision(HIW"\n$N"HIW"ͻȻ����  ����������!!  һ������������$n��\n"NOR,this_object(),target);
        this_object()->add("zhen", -1);
        msg = HIW"$N"HIW"��������,��֪�������Ѷ�׼��$n"HIW"��$n"HIW"�������캮���������Ծ��\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
       if ((int)target->query("magicgift")==2)
{
damagic=100+damage;
                target->receive_damage("qi", damagic);
damagic=50+damage;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
}
else  if ((int)target->query("magicgift")==1)
{
damagic=500+damage*4;
                target->receive_damage("qi", damagic);
damagic=500+damage*2;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
}
else 
{
damagic=250+damage;
target->receive_damage("qi", 250+damage*2);
target->receive_wound("qi", 250+damage);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
}

        msg += HIW"$n"HIW"����û����ܣ�һ���޴�ĺ�����,�˶���\n"NOR;
        msg += HIW"������$n"HIW"�����ϣ�$n"HIW"ȫ����ס��!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIW"����$p"HIW"����һЦ��������ת.\n"NOR;
        msg += HIW"��������$p"HIW"��໮�����������ˡ�\n"NOR;
		message_combatd(msg, me, target);
        }
if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);
                me->start_busy(2);
        return 1;
}
