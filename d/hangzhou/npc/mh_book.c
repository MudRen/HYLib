//Cracked by Kafei
// /d/hangzhou/mh_book.c
// by aln  2 / 98

inherit ITEM;

void create()
{
        set_name("�����鼭�ԡ�", ({ "mingshi", "shi", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
"����һ����ʷ���˺���ׯ���������ͨʿ������������ԭ����ɾ���ɡ�\n");
                set("value", 80);
                set("material", "paper");
        }
}
