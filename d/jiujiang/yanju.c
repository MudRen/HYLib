
#include <ansi.h>
inherit ROOM;

#define JOBNAME "�Ž�"

void create ()
{
  set ("short","�ξ�");
  set ("long", @LONG
�����ǾŽ����ξ֣��ܹܾŽ������ˡ���������ս�ң���䷷��˽
�ε������Ž���ֹ�������ξֵ����Ⲣ���Ǻܺá������ٸ�����һЩ��
�������Σ����ǻ�Ҫ��ֹ���˰�·�����γ���������Ӧ�ٵĴ󲿷ֶ���
�����е����ֻ��һ���ξֵĹٲ��������ݵ�վ�������ʱ���˴�
�����������γ�������ȥ��
LONG);

  set("exits", ([ 
 "south":__DIR__"xidajie2",
       ]));
  set("objects",([
	  __DIR__"npc/guanchai":1,
	  ]));
  set("job_name",JOBNAME);
  set("valid_startroom", 1);
  setup();
 
}

