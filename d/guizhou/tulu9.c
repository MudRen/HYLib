inherit ROOM;

void create()
{
	set("short", "����ʯ��");
	set("long", @LONG
�������ڶ�����ʯ�εض����ƽ���ꪣ�����ֱ�̲�
񷡣ʯ����ߴ�30���ף����е�Ͽʯ���������ۡ���������
�١��֦�������ʸ�ʯ�壬ʹʯ��ƽ���˼������飬���
�ˡ���ɫ��ʯ�ֵ����������������������ʯ�ζ�Ӯ���ˡ���
̬����԰����������  
LONG );

	set("exits", ([
               "southwest"      : __DIR__"xiaolu1",
               "southeast"      : __DIR__"tulu8",
             	]));
        set("objects", ([
		"/clone/npc/man": 1,
	]));
 	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



