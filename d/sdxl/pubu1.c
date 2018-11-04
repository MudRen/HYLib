// xtj
// by dubei

#include <ansi.h>
#include <room.h>

inherit ROOM;
int do_jump(string arg);
int do_hit(string arg);

void create()
{
    set("short", "ɽ����");
    set("long", @LONG
������ɽ��ֻ�У�ˮ��������ɽ���ͷ����¡��¡�ĳ��������
�������ˣ�����֧�Ź�һ�����ʱ�֡�
LONG
    );

    set("outdoors", "xiangyang");
     set("no_clean_up", 0);

    setup();
 
}
void init()
{
	add_action("do_jump", "jump");
	add_action("do_hit", "hit");
	add_action("do_hit", "ji");
}
 
int do_jump(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("����æ���أ�\n");
	if (arg != "anshang" && arg != "shore")
           return notify_fail("��Ҫ����������\n");
        	me->move(__DIR__"pubu");
	message_vision("$N��Ȼ��ɽ����Ծ�˳������㲽��ϵ������˰��ߡ�\n", me);
	return 1;
}
 

int do_hit(string arg)
{
	object me = this_player();
	object weapon;
        int i;
        i = me->query_int();
       weapon = me->query_temp("weapon");
 

	if (me->is_busy() || me->is_fighting())	return notify_fail("����æ���أ�\n");
 
	if (arg != "flood" && arg != "hongshui") {
		write("������ʲô��\n");
		return 1;
	}
	if (!weapon || weapon->query("skill_type") != "sword")
        {        
		write("�����ɽ��ȭ�������һ�󣬸е���ƣ������\n");
		return 1;
        }
        if (me->query_skill("xuantie-jianfa",1) <= 120 &&
        weapon->query("id") != "xuantie jian"){
                write("�㲻�������ؽ������������������أ�\n");
        		return 1;
	}
         if (me->query_skill("xuantie-jianfa",1)>120 && 
             me->query_skill("xuantie-jianfa",1)<=160 &&
       weapon->query("id") != "changjian"){
                write("�����һ�����������������Ϊ��Ҫ��һ�ѽ��ˡ�\n");
        		return 1;
	}   
         if (me->query_skill("xuantie-jianfa",1)>160 && 
             me->query_skill("xuantie-jianfa",1)<=300 &&
        weapon->query("id") != "mu jian"){
                write("�����һ�����������������Ϊ��Ҫ��һ��ȥ�����ˡ�\n");
        		return 1;
	} 
   
 
	if (me->query("neili") < 60) {
		write("����������㣬�޷���������ȥ��\n");
		return 1;
	}
	if (me->query("qi") < 60) {
		write("���Ѿ������ˣ��޷���������ȥ��\n");
		return 1;
	}
 	if (me->query("jing") < 60) {
		write("�㾫�����㣬�޷���������ȥ��\n");
		return 1;
	}
       if (me->query_skill("xuantie-jianfa",1) <= 30){
	    me->improve_skill("xuantie-jianfa",i/3);
            me->improve_skill("force", i / 10);
	message_vision("$N��"+weapon->name()+"����������ɽ�飬���е�"+weapon->name()+"��������΢�����졣\n",me);
        write("���ƺ�������������������֮����������");
        me->receive_damage("qi", 20);
	me->add("neili", -20);
        me->add("jing",-50);
		return 1;
	}
	else 
       if (me->query_skill("xuantie-jianfa",1) <= 60){
	    me->improve_skill("xuantie-jianfa", i/2);
           me->improve_skill("force", i / 8);
	message_vision("$N��"+weapon->name()+"����������ɽ�飬���е�"+weapon->name()+"���������͵����졣\n",me);
        write("���ƺ�������������������֮����������");
        me->receive_damage("qi", 5);
	me->add("neili", -10);
        me->add("jing",-25);
		return 1;
	}
	else 
       if (me->query_skill("xuantie-jianfa",1) <= 90){
	    me->improve_skill("xuantie-jianfa", i);
            me->improve_skill("force", i / 5);
	message_vision("$N��"+weapon->name()+"����������ɽ�飬���е�"+weapon->name() + "������ˢˢ�����졣\n",me);
        write("���ƺ��������������Ĳ���֮����������");
        me->receive_damage("qi", 5);
	me->add("neili", -10);
        me->add("jing",-20);
		return 1;
	}
	else 
       if (me->query_skill("xuantie-jianfa",1) <= 120){
	    me->improve_skill("xuantie-jianfa",i*2/3);
	message_vision("$N��"+weapon->name()+"����������ɽ�飬���е�"+weapon->name()+"������¡¡�ľ�����\n",me);
        write("���ƺ����������������ھ�������������");
        me->receive_damage("qi", 5);
	me->add("neili", -10);
        me->add("jing",-30);
		return 1;
	}
        else 
       if (me->query_skill("xuantie-jianfa",1) <= 150){
	    me->improve_skill("xuantie-jianfa", i);
	message_vision("$N��"+weapon->name()+"����������ɽ�飬���е�"+weapon->name()+"������ˢˢ�����졣\n",me);
        write("���ƺ��������������ľ�����������");
        me->receive_damage("qi", 5);
	me->add("neili", -10);
        me->add("jing",-20);
		return 1;
	}
        else 
       if (me->query_skill("xuantie-jianfa",1) <= 180){
	    me->improve_skill("xuantie-jianfa", i);
	message_vision("$N��"+weapon->name()+"����������ɽ�飬���е�"+weapon->name()+"���������͵����졣\n",me);
        write("���ƺ�������������������֮����������");
	me->add("neili", -10);
        me->add("jing",-20);
		return 1;
	}
        else 
     if (me->query_skill("xuantie-jianfa",1) <= 270){
	    me->improve_skill("xuantie-jianfa", i);
	message_vision("$N��"+weapon->name()+"����������ɽ�飬���е�"+weapon->name()+"��Ȼ������\n",me);
        write("���ƺ�������������������֮����������");
	me->add("neili", -10);
        me->add("jing",-20);
		return 1;
	}
 
       message_vision("$N��"+weapon->name()+"����������ɽ�飬���е�"+weapon->name()+"��Ȼ������\n",me);
       write("���Ѿ��޷���������������������������Ϊ�ˣ�\n");
        return 1;
}
 
