// sz:shenzhen.c
// 97.10.1   by Aug

inherit ROOM;

void create()
{
      set("short", "��������");
	set("long", @LONG
��������������Ҷ��������ס����լ�����еĳ�������ӵ���ʧ����
�ҷ緶������������Ȼ��Щ�¾ɣ������������ܽ�ʵ���̵ص�ʯ��Ҳ����
ĥ��ĺۼ�����֮һ�ж���ʾ��Ҷ���ƾõ���ʷ�����������������۵Ķ�
�����������ϵ��ǿ���ִ���(bian)�����ݴ��⻹���ն��µ��ּ��أ���
�Ǹ���ɫ�����ҩ��(yaojia)���������Ҷ�������������صĸ�Դ���ڡ�
LONG
);

	set("objects", ([ /* sizeof() == 1 */
		__DIR__ "npc/shenyi" :  1,
	]));

	set("item_desc", ([ /* sizeof() == 1 */
		"yaojia" : "ҩ���ϰ�����ҩƿ��ҩ�ޣ�һ������ﻹ�м�ö������������롣\n",
		"bian" : "������д���ĸ���������Ĵ��֣������������ҡ���\n",
	]));

	set("no_fight",1);
	set("no_magic",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	

      set("exits", ([ /* sizeof() == 1 */
	    "north" : "/d/pingan/west2",
	]));
      
	setup();
	replace_program(ROOM);
}

