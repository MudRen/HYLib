
#include <ansi.h>
inherit ROOM;

#define JOBNAME "�Ϸ�"

void create ()
{
  set ("short","�Ϸ��ξ�");
  set ("long", @LONG
�����ǺϷʵ��ξ֣��ܹܺϷʵ����ˡ���������ս�ң���䷷��˽
�ε������Ž���ֹ�������ξֵ����Ⲣ���Ǻܺá������ٸ�����һЩ��
�������Σ����ǻ�Ҫ��ֹ���˰�·�����γ���������Ӧ�ٵĴ󲿷ֶ���
�����е����ֻ��һ���ξֵĹٲ��������ݵ�վ�������ʱ���˴�
�����������γ�������ȥ��
LONG);

  set("exits", ([ 
 "north":__DIR__"xidajie3",
       ]));
  set("objects",([
	  __DIR__"npc/wujiang":1,
	  __DIR__"npc/bing":2,	
	  ]));
  set("job_name",JOBNAME);
  set("valid_startroom", 1);
  setup();
 
}

