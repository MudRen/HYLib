
#include <ansi.h>
inherit ROOM;

#define JOBNAME "��Ҷ"

void create ()
{
  set ("short","�ξ�");
  set ("long", @LONG
��������Ҷ���ξ֣��ܹ���Ҷ�����ˡ���������ս�ң���䷷��˽
�ε������Ž���ֹ�������ξֵ����Ⲣ���Ǻܺá������ٸ�����һЩ��
�������Σ����ǻ�Ҫ��ֹ���˰�·�����γ���������Ӧ�ٵĴ󲿷ֶ���
�����е����ֻ��һ���ξֵĹٲ��������ݵ�վ�������ʱ���˴�
�����������γ�������ȥ��
LONG);

  set("exits", ([ 
 "east":__DIR__"nandajie1",
       ]));
  set("objects",([
	  __DIR__"npc/wujiang":1,
	  __DIR__"npc/guanbing":2,	
	  ]));
  set("job_name",JOBNAME);
  set("valid_startroom", 1);
  setup();
 
}

