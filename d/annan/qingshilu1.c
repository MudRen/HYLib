
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
����������ʯ·���ϱ߾��ǰ��ϵ������ˣ��Ǳߴ��������ֵ�������
������һ�Ҽ�Ժ�����洫��������Ц�����м���Ů�������ſ��к�����
���Ŀ��ˣ���Ȼ�кܶ๫�Ӹ硢����ç���������ȥ�ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"center",
  "east":__DIR__"yingjunlou",
  "north":__DIR__"qingshilu2",
       ]));
 
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

