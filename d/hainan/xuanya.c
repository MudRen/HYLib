// Room: /d/hainan/xuanya
inherit ROOM;

void create ()
{
  set ("short", "�����ض�");
  set ("long", @LONG
���������¼��һ��ɽ��,���ڵ�ɽʯ������Ϊ������,�Ե�ʮ�ֱ� 
��.����������ѷ�,һ�ֲ�֪����ֲ����ѷ�����������,���ұ�Ⱦ��һ 
Ƭ��ɫ.������һ�������ε���ʯ�м�,����һ��ҹ����. 
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhonglin.c" : 1,
]));
  set("item_desc", ([ /* sizeof() == 2 */
  "ֲ��" : "һ��Ҷ�ӳ�ѩ�������͵�ֲ��,��������˺�ɫ�Ĺ���,��֪�� 
ժ(pick ����)������ζ������! 
",
  "ҹ����" : "һ�������ҹ����,��ʹ�ڰ��ڵĵط�,Ҳ�ܷ�������Ĺ�ã. 
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "eastup" : __DIR__"midao",
]));

  setup();
}
void init()
{
    add_action("do_pick","pick");
}
int do_pick(string str)
{ 
	if( !living(this_player()))	return 0;
  if (str!="����") return notify_fail("��Ҫժʲô?\n");
message_vision("$N������ʯ�ڵ�ֲ����ժ��һ�ź�ɫ����!\n",this_player());
clone_object("/d/hainan/obj/shanhu.c")->move(this_player());
return 1;
}
