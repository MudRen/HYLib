// /d/yazhang/yaopu.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "ҩ��");
	set("long", @LONG
���Ƕ��������ҩ�꣬���������ҩ�����Ե�����ҽ֮�֣�����
��������Ȼ�۸�Ҳ�����ˣ����Թ������Ĵ������Ǯ���뽭�����ˡ�
����ƽ�տ�����������ģ�ֻ�м���ҩ��С������ڴ��˯��
LONG
	);
set("exits", ([
                 "east" : __DIR__"beidajie1",  
	]));
      
      set("objects",([
         __DIR__"npc/zhoulaoban":1,
         ]));
      
       setup();
	replace_program(ROOM);
}	
