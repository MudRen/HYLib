// topboard.c
// ����2000/4/8

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY"������Ӣ�۰�"NOR, ({ "hero board", "board" }));
        set_weight(800);
        set("unit", "��");
        set("long",HIY"                                    ����Ӣ�۰�
          
    "HIW"���Ǽ�¼��������100��������һ��Ӣ�۰�����Ӣ�۲��۳����������߶������ϰ�\n\n"

HIC"                topten exp     ������100����IIʮ��������а�
                topten rich    ������100����IIʮ�������а�
                topten pker    ������100����IIʮ��ɱ�˿����а�
                topten neili   ������100����IIʮ�������������а�
                topten shen1   ������100����IIʮ���������а�
                topten shen2   ������100����IIʮ��ħͷ���а�
                topten per1    ������100����IIʮ��˧�����а�
                topten per2    ������100����IIʮ���������а�
                topten age     ������100����IIʮ����������а�\n"NOR);
        set("value", 1600);
        set("material", "paper");
        set("no_get",1);
}
