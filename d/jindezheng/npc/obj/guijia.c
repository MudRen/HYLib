inherit ITEM;
void create()
{
     set_name("��ɫ���",({"guijia","jia"}));
     set_weight(3000);
     if (clonep())
       set_default_object(__FILE__);
     else {
                 set("unit","��");
                 set("long","�ں�ɫ�Ĺ�ף�������Щ�����ͼ��.\n");
                 set("material","bone");
                 set("value",10000);
                 set("skill",([
                                   "name":"literate",
                                   "exp_required":100,
                                   "jing_cost":10,
                                   "max_skill":40,
                        ]));
              }
}