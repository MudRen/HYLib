// /d/zhuojun/xiaoxiang.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "��´��Ժ");
	set("long", @LONG
ȫ���Ĵ���Ժ֮�׵���´��Ժ��λ����´ɽ���Ͽ��
�ڴ�����ǧ�����˥����������������������ͼ�����
��ѧ�кܴ��ϵ����Ժ���š��á�ͤ��̨��¥������
��ի����������ɣ�����"Ψ���вģ���˹Ϊʢ"������
�񣻴�����������"��Т����"ʯ�������������念����
Ǭ¡�ʵ�����"ѧ������"��"��������"������������Ŀ
��"��´��Ժ"�ഫΪ�������ּ���
LONG
	);
set("outdoors", "changsha");
set("exits", ([
                "west"  :__DIR__"beidajie1",
	]));
	
      set("objects",([
            "/clone/npc/man":2,
                  "/d/wudujiao/npc/xuetong": 3,
                  "/d/wudujiao/npc/xiansheng": 1,
            ]));
       setup();
	replace_program(ROOM);
}	
