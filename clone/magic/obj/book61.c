// ���Լ�����

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
        set_name(HIY"���Լ�����"NOR, ({ "dele axes", "1axes" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ħ���������ʹ��(spell id)�����ħ����\n") ;

                set("unit", "��");
                set("value", 30000);
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

        me = this_player();

 	if (!id(arg))
	return notify_fail("��Ҫʹ��ʲô���᣿\n");
        if( !arg ) return notify_fail("�����˭ʹ�����Լ����᣿\n");

      if( !target ) target = offensive_target(me);

      if( !target || !target->is_character() || !me->is_fighting(target) )
              return notify_fail("���Լ�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !target->is_character() || target->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if( me->query("combat_exp")< 500000)
        return notify_fail("��ľ���̫���ò��ˣ�\n");



if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");

        if(me->is_busy() )
                return notify_fail("����æ���ġ�\n");

        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIY"\n$N"HIY"�ϵ�ħ������������!  $N"HIY"��ʧ�ˡ�\n"NOR,this_object(),target);
        destruct(this_object());
return 1;
                }

        if( !objectp(ob = present("dele axes", me)) )
                return notify_fail("��û�����ֶ�����\n");

        message_vision(HIY"\n$N"HIY"ͻȻ����  ̽��Ⲩ��!!  һ���׹����$n��\n"NOR,this_object(),target);
if ((int)target->query("magicgift")==1)
tell_object(me, HIR"\n���˵����������ǻ�\n" NOR);
if ((int)target->query("magicgift")==2)
tell_object(me, HIW"\n���˵�����������ˮ��\n" NOR);
if ((int)target->query("magicgift")==3)
tell_object(me, HIC"\n���˵���������������\n" NOR);
if ((int)target->query("magicgift")==4)
tell_object(me, YEL"\n���˵���������������\n" NOR);
if ((int)target->query("magicgift")==5)
tell_object(me, BLK"\n���˵����������ǰ���\n" NOR);
if ((int)target->query("magicgift")==6)
tell_object(me, HIY"\n���˵����������ǹ⡣\n" NOR);
if (!target->query("magicgift"))
tell_object(me, HIG"\n����û���������ԡ�\n" NOR);

        this_object()->add("zhen", -1);
        me->start_busy(1) ;
        return 1;
}
