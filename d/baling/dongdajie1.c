// baling/dongdajie1
// Room in ���� 
// laowuwu 99/04/11 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣�����������ӡ���
����һ�����ӵ�Ժ�ӣ������εĴ����Ϸ�д�š���ɽ���ݡ��ĸ����֣�
�Ծ����������治ʱ�ش���ѧ��������ٴ�Ķ��������ϱ���һ�ҿ�ջ��
LONG
	);
        set("outdoors", "baling");

	set("exits", ([
		"east" : __DIR__"dongmen",
		"west" : __DIR__"guangchang",
		"south" : __DIR__"kedian",
		"north" : __DIR__"shuyuan",
	]));
          set("objects", ([
              "/clone/misc/dache" : 1,
        ]) );
	setup();
	replace_program(ROOM);
}

