// "suiye"/qianzhuang
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "Ǯׯ");
	set("long", @LONG
����ȫ����ģ����һ��Ǯׯ����˵�����ǻ��ף���ȫ�����ض���
�ֵ꣬�ٸ���ʱҲ�������������е���Ʊͨ��ȫ����Ǯׯ���ſڹ���һ
��ܴ�Ľ������ƣ�����"���Ǯׯ"�������Ĵ����������Ĺ�̨������
ɨ�ĸɸɾ������߸ߵĹ�̨�󼸸��˷�������С�������æ�Ľ�ͷ�ö
��̨�Ϸ���һ������(sign)�������Ŵ�ҡ�
LONG);

set("exits", ([
		
                "west":__DIR__"beidajie1",
	]));
set("objects",([
   __DIR__"npc/qian":1,
   ]));
   
   set("item_desc",([
       "sign":"���Ĵ�ȡ\n",
       ]));
       setup();
	replace_program(ROOM);
}	
