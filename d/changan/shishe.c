inherit  ROOM;
#include  <ansi.h>;
void  create  ()
{
    set  ("short",  "�ָ�ʫ��");
    set  ("long",  @LONG
��¥֮�ϣ����Ƿ��������۵ס�����ɧ�Ͷ�ϲ��������Ʒ����
ʫ��̸���۽����ƣ���֪˭�ڲ����ϸո�д��һ��ʫ(poem)����
�߹�̨��������������(qishi)���㲻�ɵ��߹�ȥ���˼��ۡ�
LONG);

    set("exits",  ([
        "down"  :  __DIR__"yuefang",
        "east"  :  __DIR__"club",
    ]));
    set("objects",  ([
        __DIR__"npc/xiucai":  1,
        __DIR__"obj/tables"  :  1,
    ]));
    setup();
}

