
#include <ansi.h>
inherit ROOM;

#define JOBNAME "����"

void create ()
{
  set ("short","�ξ�");
  set ("long", @LONG
�����ǰ��ϵ��ξ֣��ܹܰ��ϵ����ˡ���������ս�ң���䷷��˽
�ε������Ž���ֹ�������ξֵ����Ⲣ���Ǻܺá������ٸ�����һЩ��
�������Σ����ǻ�Ҫ��ֹ���˰�·�����γ���������Ӧ�ٵĴ󲿷ֶ���
�����е����ֻ��һ���ξֵĹٲ��������ݵ�վ�������ʱ���˴�
�����������γ�������ȥ��
LONG);

  set("exits", ([ 
 "south":__DIR__"xijie2",
       ]));
  set("objects",([
	  "/clone/npc/man":3,
	  ]));
  set("job_name",JOBNAME);
  set("valid_startroom", 1);
  setup();
 
}

