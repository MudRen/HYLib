// �س���

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
        set_name(HIY"�س�������"NOR, ({ "portal axes", "31axes" }) );
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
	string startroom;
        me = this_player();

 	if (!id(arg))
	return notify_fail("���޷�ʹ���������!\n");

        if(me->is_busy() )
                return notify_fail("����æ���ġ�\n");
        if( me->query("combat_exp")< 500000)
        return notify_fail("��ľ���̫���ò��ˣ�\n");

        if (me->query("neili") < 400)
        return notify_fail("��ķ������㣡\n");
        if (me->is_fighting()) 
        return notify_fail("���������������!\n");
        if (me->is_busy()) 
        return notify_fail("����æ����!\n");

	if( environment(me)->query("outdoors")=="12gong" )
		return notify_fail("��12���ڲ�����ʹ�ûس�����\n");

   if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR)
	return notify_fail("ֻ���ڱȽϰ�ȫ�ĵط�����ʹ�ûس�����\n");
	
        if( !environment(me)->query("no_fight") )
		return notify_fail("ֻ���ڱȽϰ�ȫ�ĵط�����ʹ�ûس�����\n");	        

        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIY"\n$N"HIY"�ϵ�ħ������������!  $N"HIY"��ʧ�ˡ�\n"NOR,this_object(),me);
        destruct(this_object());
return 1;
                }

        if( !objectp(ob = present("portal axes", me)) )
                return notify_fail("��û�����ֶ�����\n");

        startroom = me->query("startroom");
        if( !me->query("startroom") )
		return notify_fail("����ȷ����Ҫȥ��Ŀ���!\n");
	me->add("neili",-150);

	message_vision(YEL "\n$N�ڵ��ϻ���һ����â�ǣ������૵���������!!\n" NOR, me);	
	message_vision(YEL "\n$Nվ�ڵĵ��ϳ����˾޴�Ĺ�â����$N��Χ��!\n" NOR, me);
        message_vision(YEL "\n$N�ڹ�â�У���ʧ������!\n" NOR, me);
        me->move(startroom);
	me->start_busy(3);
        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIY"\n$N"HIY"�ϵ�ħ������������!  $N"HIY"��ʧ�ˡ�\n"NOR,this_object(),me);
        destruct(this_object());
return 1;
                }

        return 1;
}
