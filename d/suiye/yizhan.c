// "suiye"/yizhan
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "��վ");
	set("long", @LONG
����һ��ʮ����ͨ����վ��ר�Ÿ���ٷ����飬�ż��Ĵ��͡�
LONG
	);
set("outdoors", "suiye");
set("exits", ([
		
                "east": __DIR__"beidajie1",
               
	]));
       setup();
	replace_program(ROOM);
}	
