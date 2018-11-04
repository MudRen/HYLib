
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"tengtiao"
#define FROM __DIR__"shanyabei"
#define TO __DIR__"shanyanan"

int do_yell(string arg);
void create ()
{
  set ("short","ɽ��");
  set ("long", @LONG
������һ��ɽ�£�λ�ڻƺӵı�������Ϊ������Ҫ������û�д���
������ڶɹ��ӵĿ��ˡ�ɽ��֮��Ʈ����һ������������������˵�书
��ǿ���˿�����������������ֱ���Ƶ��������ɽ��ȥ��Ҳ��֪������
�Ǽ٣������yell tengtiao���Կ���
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shanlu4",
         ]));

  set("valid_startroom", 1);
  set("outdoors","huanghe");
  setup();
 
}

void init()
{
	
	add_action("do_yell","yell");
	
}  

int do_yell(string arg)
{
	object ship,here,me;int force;
	ship=find_object(SHIPDIR);
	ship=load_object(SHIPDIR);
		
	me=this_player();
	
	if(me->is_busy())
	return notify_fail("����æ���أ�\n");
	if(me->is_fighting())
	return notify_fail("���ȴ����̰ɣ�\n");
		
	here=environment(me);
	force=me->query("neili");
	if(!arg||arg!="tengtiao") return notify_fail("��Ҫ����ʲô?\n");
	if(force<200||me->query_skill("force",1)<20){
	 tell_object(here,me->name()+"ʹ�������������������𣿰��æ�������ӹ�������\nԶ��ֻ�Ǵ�����Ļ�����\n");
	 return 1;
	}
	if(force<=1000) tell_object(here,me->name()+"��������:�����𣿰��æ�������ӹ�������\n");
	else if(force<=2000) tell_object(here,me->name()+"����������������:�����𣿰��æ�������ӹ�������\n");
	else tell_object(here,me->name()+"��������:�����𣿰��æ�������ӹ���������������,���ò�Ϣ��\n");
	if(ship->query("yell"))
	 return notify_fail("\n��������ʹ���������ȵȰɣ�\n");
	
	ship->set("yell",1);	
	message_vision("������Լ���˽е������ˣ�ע���ס�ˣ�һ���������˹�����$N��æץ�����\n",me);
	me->move(SHIPDIR);
	remove_call_out("do_flying");
	call_out("do_flying",10,me,ship);
	return 1;
}

void do_flying(object me,object ship)
{
   message_vision("$N��������һ�٣�˫�ŽӴ�����ʵ�أ��Ѿ���ȫ�ĵ��������ɽ�£�\n",me);
   ship->delete("yell");
   me->move(TO);
}

