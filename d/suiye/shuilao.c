// "suiye"/shuilao
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "ˮ��");
	set("long", @LONG
�����ϰ�Ϊ���ȹ���ӿ�׼����һ��ˮ�Σ��������̾���ȫ��һ��
�����Ĺ���������������������ĵ��ϰ岻��������Ŀ޺ţ��Դ�
һ��ǰ��һ��������������󣬼���û���ٸҷ����ϰ壬��ǰ�������
�ټˣ����˼���Ҳ���������ϰ���ϻ�
LONG
	);
set("exits", ([
		
             "north":__DIR__"houyuan",
        ]));
       setup();
	replace_program(ROOM);
}
