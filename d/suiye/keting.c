// "suiye"/keting
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
����Ԫ˧���͵ĵط����ྻ�Ĳ輸�ϰ���һ������Ĵ�����ǽ�Ϲ�
��һ�����������������ڴ�ɨ�ŷ��ݡ�
LONG
	);
set("exits", ([
		
                "east"  : __DIR__"shuaifu",
                
	]));
       setup();
	replace_program(ROOM);
}	
