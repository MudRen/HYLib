// "suiye"/datiepu
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
�߽����ֻ���ıڰ��������λεı��У�һ�����̻�صĴ���
�Ӷ����������������ı����䲻��ʲô�����������Ҳ�������򾫸�
�����������쳣����Ҫ��ȱ�ٱ����Ļ�����Ȼ���Ե�����������һ����
�ֵġ�
LONG
	);
set("exits", ([
		
                "west":__DIR__"beidajie2",
	]));
     set("objects",([
         __DIR__"npc/tiejiang":1,
         ]));
       setup();
	replace_program(ROOM);
}	
