
inherit ROOM;


void create ()
{
  set ("short","С�Ե�");
  set ("long", @LONG
������һ��С�Եꡣ�����ϲ����οͺܶ࣬���Ե��������ܺá�
��С��������ȥ��æ����ͣ��ֻ������������Щ�����ˣ������������
̸������������ʽ���Ա߻��м����ٲ���ոֵ��������ע������
�ǣ��ƺ�һ����ս������ʼ�ˡ�
LONG);

  set("exits", ([ 

  "east":__DIR__"beidajie1",
        ]));
  set("objects",([
	  __DIR__"npc/xiaoer":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

