
inherit ROOM;


void create ()
{
  set ("short","�ϴ��");
  set ("long", @LONG
�������ϲ����ϴ�֡��������ϲ��������ˡ�����Ҳ�������֡���
���������������ַǷ����������ϲ�������ļң�ֻ���ſ�վ�ż�����
���������ע�������������ˡ�����������Ů��Ҫ���������ˣ�����
�Ҷ�����Ҫ�úÿ����ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"nandajie2",
  "north":__DIR__"center",
  "west":__DIR__"dafu",
        ]));
  set("objects",([
       "/clone/npc/man":1,
       ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

