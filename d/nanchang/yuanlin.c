
inherit ROOM;


void create ()
{
  set ("short","԰��");
  set ("long", @LONG
������һ��԰�֣����ﾰɫ���ˡ�����Ҳ�кܶ���ο͡�����ļ�
ɽ��״���أ��й���֮���������������������������ļ�ɽ��
ֻ����ɽͻ��֮������һ�������ң�����д�ţ�̫ƽ ���֣�����Ѿ���
��������ƺ����ϲ���ĳ��֪�������֡��������֡�
LONG);

  set("exits", ([ 

  "south":__DIR__"dongdajie2",
   "northeast":__DIR__"jiashan",
        ]));
  set("objects",([
	  __DIR__"obj/xianrenzhang":2,
	  ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

