
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�������������500���꣬�Ǻ��ڵ�һ�������羰�����ż�������Ҳ�Ƚ�
���У�����¡�����ۡ������µȣ�����ڹ�����¡�λ�ں��ڻ���������
�����ǹŴ����������ӵĵط��������������ϣ���ǽ���ߣ���һ������
���й����Ľ���Ⱥ�����Կ��������й���ͳ�Ļ����������ԨԴ�� 
LONG);

  set("exits", ([ 
"east":__DIR__"center",	

       ]));
 set("objects",([
	 "/clone/npc/man":1,
	 ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

