
#include <ansi.h>
inherit ROOM;

#define JOBNAME "����"

void create ()
{
  set ("short","������");
  set ("long", @LONG
�������������󣬹�����Ϊ���������޽����������ڵ����У�
��������������������������Ϊ�������飺��׳˼��ɳ�������
���͹ⴺ��ˬ����ߡ�ľ�̶����������Ɱ�����������������顶
��ͤ�ǡ��ͼ����ĸ弰�������
LONG);

  set("exits", ([ 
 "south":__DIR__"xidajie",
       ]));
  set("objects",([
	  "/clone/npc/man":2,
	  ]));
  set("job_name",JOBNAME);
  set("valid_startroom", 1);
  setup();
 
}

