//  Room:  /d/city/road4.c

inherit  ROOM;

void  create  ()
{
	set("short",  "��ٵ�");
	set("long",  @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�������ͨ��
���ȹأ�������ֱ�ﳤ���ǡ�
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"      :  __DIR__"baqiao",
		"southeast" :  __DIR__"road3",
	]));
	set("objects", ([
                "quest/skills2/wunon/dalie/dalie" : 2,
	])); 

	set("outdoors",  1);
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}






