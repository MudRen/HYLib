// "suiye"/yaopu
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "ҩ��");
	set("long", @LONG
������Ҷ����ҩ�꣬���������ҩ�����Դ�����ҽ֮�֣����Ͽ�
������Ȼ�۸�Ҳ�ܸ��ˣ����Թ������Ĵ������Ǯ���뽭�����ˡ���
��ƽ�տ�����������ģ�ֻ�м���ҩ��С������ڴ��˯���ϰ岻֪��
ȥ�ˡ�
LONG
	);
set("exits", ([
		
		"south" :  __DIR__"xidajie2",
                 
	]));
	
	set("objects",([
	   __DIR__"npc/shen":1,
	   ]));
	
       setup();
	replace_program(ROOM);
}	
