// "suiye"/houyuan
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "��Ժ");
	set("long", @LONG
���Ǽ�Ժ�ĺ�Ժ����ΪһЩȨ��׼���ģ��߸ߵ�Ӱ��ǽ��ס��һ��
Ư����С�ݣ�С���ﲻʱ����һ����Ц����Ժ����������һ���ϰ�˽��
��ˮ�Σ�����ʱ�б޴�����������
LONG
	);
set("outdoors", "suiye");
set("exits", ([
		
               "east":__DIR__"xiaowu",
               "westup" :__DIR__"jiyuan",
               "south" :__DIR__"shuilao",
       ]));
       setup();
	replace_program(ROOM);}
