// Room: /d/pingan/pingankezhan
inherit ROOM;

void create ()
{
  set ("short", "ƽ����ջ");
  set ("long", @LONG
�����ƽ�������������Ŀ�ջ��˵����������Ҳ����ֻ��СС�ļ���
���棬һ�������ĵ�С��վ�ڹ�̨ǰ�棬��Ц����ӭÿһ�������Ŀ��ˡ���
Ϊ�������û�иߵ͹�������˶��ǿ��Լ����Ͷ�������Ͷ��ǿɳܵ���
Ϊ������ǰ����һ��СС�����ƣ�paizi����
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer" : 1,
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "���꼱�蹤����Ա������������С������[����]���¡�
",
]));
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"chufang",
  "west" : __DIR__"kefang",
  "south" : __DIR__"tingtang",
  "east" : __DIR__"nan1",
]));
  set("pingan", 1);
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("no_dazuo", 1);
  set("no_kill", 1);
  set("valid_startroom", 1);

  setup();
//  replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
	if (dir =="west")
	{
		if ( me->query("PKS") >= 3)
		return notify_fail("��ɱ��̫�����ң�ƽ���ǲ���ӭ�㣡\n");
	
		if ( me->query("age") >= 18)
		return notify_fail("����ô������Ҳ����˯������Ǯ��\n");
	
	
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�����ȥ�����˿ڣ�\n");
       		
		}
		
	}

	return ::valid_leave(me, dir);
}
