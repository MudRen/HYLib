// "suiye"/zhubaodian
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
����һ��ר�ų��۹��ر�����鱦�ꡣս������Ѿ������˹����
��ϡ��ļ����鱦�������˻ҳ�����Ҫ������ȥ�ֺ���������˵Ļ���
��Ҫ����ԥ�ˣ����ﻹ�����������Ҫ��ġ�
LONG
	);
set("exits", ([
		
		"north" :  __DIR__"xidajie1",
               
	]));
 set("objects",([
  __DIR__"npc/zhou2":1,
  	]));	
       setup();
	replace_program(ROOM);
}	
