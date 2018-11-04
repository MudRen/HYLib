//Cracked by Kafei
// ���ոİ�
// maco 2/17/2000
#include <room.h>

inherit ROOM;
void wakeup(object me, object where);

void create()
{
	set("short", "����˯��");
	set("long", @LONG
�����ǰ���ɽ������˯���᷿����������屻���������ʣ������
������������棬������գ�ǽ�߹���������ң������ð�˿������һ
ֻ���ա�˯����ʱ���������ļ���ڴ��̺򣬶��Ǹ����������ļ�����
�Ǹ������硣
LONG
	);
	set("sleep_room", 1);
	set("no_fight", 1);
	set("exits", ([ 
	    "southeast" : __DIR__"changlang",
	]));
	set("objects", ([
	    __DIR__"npc/shiji" : 2,
	 ]) );
	set("cost", 1);
	setup();
}
void init()
{
	add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
	object shiji, me, where;
	
	me = this_player();
	where = environment(me);

	seteuid(getuid());

	if (me->is_busy())
		return notify_fail("����æ���أ�\n");

	if (me->query("family/family_name") != "����ɽ��") {
		write("�㲻�ǰ���ɽ���ˣ�����˯�������\n");
		return 1;	
	}
	if (me->query("family/master_id") != "ouyang feng" ){
		if(shiji = present("shi ji", environment(me))) {
			message_vision("$N�������ϴ�ȥ˯������Ȼ��$n����ס�����졣\n"
			"$n����$Nһ�ۣ������"+RANK_D->query_rude(me)+"������������ķ��䣬����ʲ���ʸ�˯�������\n\n", me, shiji);
			me->move("/d/baituo/changlang");
			tell_object(me,"\n�㱻�̼�������˯������˳�����\n");
			message("vision",me->query("name") + "��ͷ�����ش�����˯�������˳���������һ�������\n", environment(me), me);
			return 1;
		}
		else {
		write("���������ķ��䣬�ɲ�����������˯�ģ�\n");
		return 1;
		}
	}
	write("��������һ�ɣ�һ���̼�����������ѥ��������̵�ʮ���ܵ���\n");
	write("�̼�������Ͻ�������һ�������ͽ��������硣\n");
	me->set_temp("block_msg/all",1);
	message_vision("$N���ڴ��ϣ�һ���̼����Է��̣���һ�����$N�ͽ��������硣\n",me);

	where->add_temp("sleeping_person", 1);
	
	me->set_temp("sleeped",1);

	me->set("disable_type", "<˯����>");
	me->set_temp("disabled", 1);
	me->disable_commands();
	me->enable_commands();

	call_out("wakeup",random(60 - me->query("con")), me, where);
	call_out("wakeup",3, me, where);
	return 1;
}

void wakeup(object me, object where)
{
	int sp, new_hp;
	object shiji;
	sp = 10 - (int)me->query_condition("sleep");

	new_hp = (int)me->query("qi");
	new_hp += ((int)me->query("eff_qi") - new_hp)*sp/10;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("eff_qi") ) new_hp = me->query("eff_qi");
	me->set("qi", new_hp);
	
	new_hp = (int)me->query("jing");
	new_hp += ((int)me->query("eff_jing") - new_hp)*sp/10;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("eff_jing") ) new_hp = me->query("eff_jing");
	me->set("jing", new_hp);

	new_hp = (int)me->query("jingli");
	new_hp += ((int)me->query("max_jingli") - new_hp)*sp/5;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("max_jingli") ) new_hp = me->query("max_jingli");
	me->set("jingli", new_hp);

	new_hp = (int)me->query("neili");
	new_hp += ((int)me->query("max_neili") - new_hp)*sp/12;
	if (new_hp < 0) new_hp = 0; 
	if (new_hp > (int)me->query("max_neili") ) new_hp = me->query("max_neili");
	me->set("neili", new_hp);
	
	if (living(me)) return;

	me->enable_player();
	while( environment(me)->is_character() )
		me->move(environment(environment(me)));
	me->apply_condition("sleep", 5 + random(3));

	if(environment(me) == where)
	{
		message_vision("$Nһ�����������̼������Ŵ��������������ػ��һ�½�ǡ�\n",me);
		me->set_temp("block_msg/all", 0);
		write("��һ���������̼��������㴩�����룬ֻ���������棬�ûһ���ˡ�\n");

	}
	else {
		message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
		me->set_temp("block_msg/all", 0);
		write("��һ��������ֻ���������档�ûһ���ˡ�\n");
	}
	where->add_temp("sleeping_person", -1);
	setup();
}
