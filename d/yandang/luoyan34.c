// Room: /d/yandang/luoyan34
inherit ROOM;

void create ()
{
  set ("short", "�¶���");
  set ("long", @LONG
����һ���¶���,��Բ�ε�����,�ú�ɫ����ʯ����,�����ǰ�ɫ��
����ʯ,�������˼�����'���¾�',�����濴,�Ǹ���԰,������ׯ������
����ĵط�,ׯ�е��Ӳ��������ǲ�׼����.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shouwei" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"luoyan35",
  "west" : __DIR__"luoyan17",
]));
  set("outdoors", "/d/yandang");

  setup();
}
int valid_leave(object me, string dir)
{
	object ob;
	mapping gt;
	seteuid(geteuid(me));
	
	if ( (me->query("family/family_name")=="�㵴��")&&(dir=="north") ) {
			ob = present("shou wei");
			if(!ob) return 1;
			{
			message_vision("\n$N��ס$n������ׯ���Ӳ��ý������¾�,����ׯ�������\n", ob, me);
			return  notify_fail("");
            }    
	    }
     return 1;
}
