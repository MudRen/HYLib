// Room: /d/hainan/jueqinya
inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG
��������һ������,���±�������,ƬƬ����,��������,ֻ��������
���İ���.��˵��ǰ�и������Ů��,��Ϊ�����亣����,�ʹӴ˵�������
ȥ,�Ӵ����ǰ���ط��ͽ���'������',�㲻��Ҳ����(jump down)��ȥ��?
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "westdown" : __DIR__"road5",
]));
  set("outdoors", "/d/hainan");
  setup();
}
void init()
{
   add_action("do_jump","jump");
}
int do_jump(string str)
{ 
    object ob;
ob=this_player();
	if( !living(ob))	return 0;
if (str!="down") return 0;
message_vision("$N�������¶�����,ͻȻһ����,��������������ȥ!\n",ob);
ob->move("/d/hainan/xialuo.c");
return 1;
}
