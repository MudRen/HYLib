// �س���

#include <ansi.h>
inherit ITEM;

int thunderspell(object me, object target)
{
	int	kee, damage, spells;
	string msg;
	int extra;
	int i;
	object weapon;
        int damagic;

	spells = me->query_skill("spells");
	if((int)me->query("neili")< 500)
	return notify_fail("��ķ���̫���ˣ�\n");

        msg = HIC"   $N��Ӱ��$n��ǰ��ʧ��!  \n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp"))
        {

        msg += HIC"$n"HIC"ͻȻ����$N�����ˣ�ֻ��ͣ���˹���!!\n"NOR;
                target->remove_all_enemy();
                me->remove_all_enemy();
		message_combatd(msg, me, target);
//		COMBAT_D->report_status(target);
        } else
        {
        msg += HIC"$n"HIC"˫Ŀһ����ʶ�������������!\n"NOR;
		message_combatd(msg, me, target);
        }
me->add("neili",-150);

	return 1;
	
}
void create()
{
        set_name(HIC"����������"NOR, ({ "invisibe axes", "41axes" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ħ���������ʹ��(spell id)�����ħ����\n") ;

                set("unit", "��");
                set("value", 140000);
                set("zhen", 1);
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
	string 	msg;
	object	env;
	object	*inv;
	int	i;
        me = this_player();

 	if (!id(arg))
	return notify_fail("���޷�ʹ���������!\n");

        if(me->is_busy() )
                return notify_fail("����æ���ġ�\n");
        if( me->query("combat_exp")< 500000)
        return notify_fail("��ľ���̫���ò��ˣ�\n");

        if (me->query("neili") < 400)
        return notify_fail("��ķ������㣡\n");

        if (me->is_busy()) 
        return notify_fail("����æ����!\n");

	if((int)me->query("neili")< 500)
	return notify_fail("��ķ���̫���ˣ�\n");
	

        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIC"\n$N"HIC"�ϵ�ħ������������!  $N"HIC"��ʧ�ˡ�\n"NOR,this_object(),me);
        destruct(this_object());
return 1;
                }

        if( !objectp(ob = present("invisibe axes", me)) )
                return notify_fail("��û�����ֶ�����\n");

	msg = HIC "$N"HIC"����һ���������૵��������ģ�\n" NOR;
       msg += HIC"$N�Ķ���ͻȻ�������������������ɫ�Ĺ�â��, $N������������͸��������\n"NOR;
       msg += HIC"  ���������� \n"NOR;
	message_vision(msg, me,target);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( !inv[i]->is_fighting(me) ) continue;
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
	me->start_busy(3);
        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIC"\n$N"HIC"�ϵ�ħ������������!  $N"HIC"��ʧ�ˡ�\n"NOR,this_object(),me);
        destruct(this_object());
return 1;
                }

        return 1;
}
